/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package core;

import data.MyPCB;
import data.Program;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;

/**
 *
 * @author hrmthw
 */
public class MyProcessControl {
    private final DefaultListModel listModel = new DefaultListModel();
    private final ArrayList readyList;
    private final ArrayList blockList;
    private MyPCB running;
    private int runDelta = 0;
    public StringBuffer action;
    public StringBuffer output;

    public MyProcessControl() {
        readyList = new ArrayList(0);
        blockList = new ArrayList(0);
        action = new StringBuffer();
        output = new StringBuffer();
        loadDemoProgram();
    }

    private void loadDemoProgram() {
        loadProgram("sys1", "system");
        loadProgram("sys2", "system");
        loadProgram("sys3", "system");
        action.append("system software loaded.\n");
    }

    public void loadProgram(String fileName, String user) {
        MyPCB newPCB;
        try {
            newPCB = new MyPCB(new Program(fileName), user);
            readyList.add(newPCB);
            action.append(newPCB.getpName()).append("(").append(newPCB.getPid()).append(") created by ").append(user).append("\n");
        } catch (FileNotFoundException ex) {
            action.append("load error, no such program files!\n");            
        }
    }

    public void step() {
        if (readyList.isEmpty())return;      
        runDelta=(runDelta>=readyList.size()-1)?0:runDelta+1;
        running = (MyPCB) readyList.get(runDelta);
        output.append(running.run()).append("\n");
        

    }

    public void block(int pid) {
        for (int i=0;i<readyList.size();i++) {
            MyPCB tmp=(MyPCB)readyList.get(i);
            if (tmp.getPid()==pid) {
                blockList.add(tmp);
                readyList.remove(i);
                action.append(tmp.getpName()).append("(").append(tmp.getPid()).append(") is blocked.\n");
                return;
            }
        }
        for (int i=0;i<blockList.size();i++) {
            MyPCB tmp=(MyPCB)blockList.get(i);
            if (tmp.getPid()==pid) {
                readyList.add(tmp);
                blockList.remove(i);
                action.append(tmp.getpName()).append("(").append(tmp.getPid()).append(") is unblocked.\n");
                return;
            }
        }       
    }

    public void kill(int pid) {
        for (int i=0;i<readyList.size();i++) {
            MyPCB tmp=(MyPCB)readyList.get(i);
            if (tmp.getPid()==pid) {
                readyList.remove(i);
                action.append(tmp.getpName()).append("(").append(tmp.getPid()).append(") is killed!\n");//TODO
                return;
            }
        }
        for (int i=0;i<blockList.size();i++) {
            MyPCB tmp=(MyPCB)blockList.get(i);
            if (tmp.getPid()==pid) {
                blockList.remove(i);
                action.append(tmp.getpName()).append("(").append(tmp.getPid()).append(") is killed!\n");//TODO
                return;
            }
        }       
    }


    public void updateModel(){
        MyPCB tmp;
        listModel.clear();
        for (int i = 0; i < readyList.size(); i++) {
            tmp = (MyPCB) readyList.get(i);
            listModel.addElement(String.format("%4d      %s     %s %s", tmp.getPid(), tmp.getpName().concat("                                ").substring(0, 35), tmp.getUser().concat("                       ").substring(0, 15),(runDelta==i)?"running":"ready"));
        }
        for (Object temp : blockList) {
            tmp = (MyPCB) temp;
            listModel.addElement(String.format("%4d      %s     %s block", tmp.getPid(), tmp.getpName().concat("                                ").substring(0, 35), tmp.getUser().concat("                       ").substring(0, 15)));
        }        
    
    }
    
    public DefaultListModel getModel(){
        return listModel;
    }
}
