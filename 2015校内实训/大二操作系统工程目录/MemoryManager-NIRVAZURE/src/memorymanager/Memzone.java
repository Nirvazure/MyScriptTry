/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package memorymanager;

/**
 *
 * @author LiFeReal
 */
public class Memzone {  //储存区定义
    private int initID;
    private int endID;
    private int length;
    private String processName;
    private boolean isFree;

    public Memzone(int _zhizhen,int _size) {
        initID=_zhizhen;
        length=_size;
        isFree=true;
    }   //构造器，输入指针和空间长度
    
    void setPeocessName(String _processName){
        processName=_processName;
    }   //改变进程名称
    
    String getProcessName(){
        return processName;
    }   //返回进程名称
    
    void changeStatus(){
        if (isFree) {
            isFree=false;
        } else {
            isFree=true;
        }
    }   //改变状态，空闲/忙碌
    
    int getInitID(){
        return initID;
    }   //返回首地址
    
    int getEndID(){
        endID=initID+length;
        return endID;
    }   //返回尾地址
    
    int getLength(){
        return length;
    }   //返回当前存储区分配长度
    
    public String toString(){
        String statusString;
        if (isFree) {
            statusString="目前空闲";
        } else {
            statusString="目前正被"+getProcessName()+"应用";
        }
        return "初地址为"+getInitID()+"占有"+getLength()+"长的空间"+statusString;
    }   //返回当前存储区状态
}
