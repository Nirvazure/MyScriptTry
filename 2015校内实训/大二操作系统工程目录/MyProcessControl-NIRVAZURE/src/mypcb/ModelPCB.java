/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mypcb;

/**
 *
 * @author LiFeReal
 */
public class ModelPCB {
     //PCB进程5状态
    final int create=1;
    final int ready=2;
    final int blocked=3;
    final int running=4;
    final int finished=5;
    //PCB状态变量
    private int status;
    int id=1000;    //pcbID

    public ModelPCB(){
        id++;   //id加没有效果
        status=create;
    }
    
    public int getID(){
        return  id;
    } 
    
    public void setStatus(int status) {
        this.status = status;
    }
    
    int getStatusCondition(){
        return status;
    }
    
    String getStatus(){
        String result = null;
        if (getStatusCondition()==1) {
            result="create";
        }
        if (getStatusCondition()==2) {
            result="ready";
        }
        if (getStatusCondition()==3) {
            result="blocked";
        }
        if(getStatusCondition()==4){
            result="running";
        }
        return  result;
    }
    
}
