/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mypcb;

/**
 *
 * @author LiFeReal\
 */
public class ModelProcess {
    
    ModelPCB pcb;
    int time;
    private String name;
    private String info;
    int blockPosition;//阻塞位置，方便block和restart函数的调用

    public ModelProcess(String _name,String _info,int _time) {
        pcb=new ModelPCB();
        name=_name;
        info=_info;
        time=_time;
    }
    
    int getTime(){
        return  time;
    }
  
    String getName(){
        return name;
    }
    
    String getInfo(){
        return info;
    }
        
    String getMessage(){
        return "\t"+getName()+"\tis\t"+pcb.getStatus()+"\tThe message is :"+getInfo();
    }
    
}
