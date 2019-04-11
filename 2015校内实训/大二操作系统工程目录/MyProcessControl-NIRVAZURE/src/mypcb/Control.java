/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mypcb;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author LiFeReal
 */
public class Control {

    ArrayList block;
    ArrayList ready;
    ModelProcess process;
    ModelProcess p1;
    ModelProcess p2;
    ModelProcess p3;
    int blockNum=0;
    boolean tmpboolean=true;    //控制菜单可见性的boolean变量
    
    public Control() {
        ready=new ArrayList(0);
        block=new ArrayList(0);
    }
    
    void menuBlock(){
        System.out.println("choose the process to block");
        Scanner input=new Scanner(System.in);
        int i=input.nextInt();
        ModelProcess _pModelProcess=(ModelProcess)ready.get(i-1);
        _pModelProcess.blockPosition=i-1;
        block(_pModelProcess);
    }
    void block(ModelProcess _p){
        if (_p.pcb.getStatusCondition()==_p.pcb.ready) {
            block.add(_p);
            ready.remove(_p);
            _p.pcb.setStatus(_p.pcb.blocked);
            System.out.println(_p.getName()+"\tThe process is blocked"+"\tblock array has"+block.size());
            blockNum++;
        }else{
            System.out.println("The process is not ready");
        }
    }
    void menuWakeup(){
        ModelProcess _pModelProcess=(ModelProcess)block.get(block.size()-1);
        restart(_pModelProcess);
    }
    void restart(ModelProcess _p){
        if (_p.pcb.getStatusCondition()==_p.pcb.blocked) {
            ready.add(_p.blockPosition,_p);
            block.remove(_p);
            _p.pcb.setStatus(_p.pcb.ready);
            System.out.println(_p.getName()+"\tThe process is waked up");
        }else{
            System.out.println("The process is not blocked");
        }
        
    }
    
    void run(ModelProcess _p){
        if (_p.getTime()>0 ){
       
            _p.pcb.setStatus(_p.pcb.running);
        }else{
            exitProcess(_p);
            _p.pcb.setStatus(_p.pcb.finished);
        }
    }
    
    void loadInitProcess(){
        ready.clear();
        block.clear();
        p1=new ModelProcess("apple", "apple is run",2);
        p2=new ModelProcess("banana", "banana is run",3);
        p3=new ModelProcess("pear", "pear is run",4);
        insert(p1);
        insert(p2);
        insert(p3);
    }
    
    void display(){
         for (int i = 0; i < ready.size(); i++) {
            ModelProcess tmp=(ModelProcess)ready.get(i);
            System.out.println(tmp.getMessage()+"\tEnd time is"+"\t"+tmp.getTime());
        }
    }
    
    void newProcess(){
        Scanner in=new Scanner(System.in);
        System.out.println("New a Process");
        System.out.println("Please enter the name");
        String name=in.next();
        System.out.println("Please enter the Info");
        String message=in.next();
        System.out.println("Please enter the time");
        int time=in.nextInt();
        ModelProcess result=create(name, message, time);
        insert(result);
    }
    ModelProcess create(String _name,String _message,int _time){
        ModelProcess result=null;
        if (true) {
            ModelProcess newProcess=new ModelProcess(_name, _message,_time);
            result=newProcess;
            result.pcb.setStatus(result.pcb.ready);
        }else{
            System.err.println("PCB's num is full");
        }
        return result;
    }
    void insert(ModelProcess _p){
        ready.add(_p);
        _p.pcb.setStatus(_p.pcb.ready);
    }
    
    void takeTurn(){//模拟时间片
        for (int i = 0; i < ready.size(); i++) {
            ModelProcess tmp=(ModelProcess)ready.get(i);
            tmp.time--;
            run(tmp);
            display();
            tmp.pcb.setStatus(tmp.pcb.ready);
            System.out.println("\tCircle\tis over");//改进，轮转时重新设exit函数，不用blocked
        }
    }
    
    void takeTurnDemo(){
        while (!ready.isEmpty()) {            
            takeTurn();
        }
    }

    private void exitProcess(ModelProcess _p) {
        if (_p.pcb.getStatusCondition()==_p.pcb.ready) {
            block.add(_p);
            ready.remove(_p);
            _p.pcb.setStatus(_p.pcb.finished);
            System.out.println(_p.getName()+"\tis finished\t"+block.size()+"process is finished");
            blockNum++;
        }else{
            System.out.println("The process is not running");
        }
    }
}
