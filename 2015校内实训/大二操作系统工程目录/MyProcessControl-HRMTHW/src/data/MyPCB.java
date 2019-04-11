/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package data;

import java.io.IOException;

/**
 *
 * @author hrmthw
 */
public class MyPCB {

    public static int pno = 0;  //总的线程数量
    private int pid;            //线程ID
    private String pName;       //线程名称

    public static int getPno() {
        return pno;
    }

    public int getPid() {
        return pid;
    }

    public String getpName() {
        return pName;
    }

    public String getUser() {
        return user;
    }

    public Program getProgram() {
        return program;
    }

    public String getpInfo() {
        return pInfo;
    }

    public int getPriority() {
        return priority;
    }
    private String user;
    private Program program;
    private String pInfo;
    private int priority;

    public MyPCB(Program program, String user) {
        this.pid = pno + 1;
        pno++;
        this.program = program;
        this.pName = program.getProgramName();
        this.user = user;
        this.pInfo = program.getCmd();
        this.priority = 0;
    }

    public String run(){
        String result;
        result = program.getCmd();
        return result;
    }
    
    public void exit(){
        pno--;
    }

}
