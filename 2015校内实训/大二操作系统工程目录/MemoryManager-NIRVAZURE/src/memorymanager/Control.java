/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package memorymanager;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author LiFeReal
 */
public class Control {
    ArrayList free;
    ArrayList busy;
    Memzone total;

    public Control() {  //
        free=new ArrayList(0);
        busy=new ArrayList(0);
        total=new Memzone(0, 100);   //初始化一个从0开始，长度为100的空间
        free.add(total);             //把total放入空闲队列
    }
    
    boolean apply(int _applySize,String _ProcessName){   //申请存储空间，输入申请的进程ID
        Scanner input=new Scanner(System.in);
        int tempoint = 0;                             //引入一个临时指针变量
        boolean canFound=false;
        for (int i = 0; i < free.size(); i++) {       //遍历，初始认为找不到
            Memzone temp=(Memzone) free.get(i);       //将free队列中的元组拿出来
            if (_applySize<temp.getLength()) {
                canFound=true;
                tempoint=i;break;                     //只要找到一个符合要求的区域，就返回该区域在线性表中的位数
            }
        }
        if (canFound) {
            
            Memzone temp=(Memzone) free.get(tempoint);    //把i对应的区域找出来
            //产生一个新的busyNew分配
            Memzone busyNew=new Memzone(temp.getInitID(), _applySize);   
            busyNew.changeStatus();
            busyNew.setPeocessName(_ProcessName);    //ERROR进程名不匹配
            busy.add(busyNew);                      //把busyNew加入到busy队列中
            //产生一个新的freeNew分配区
            Memzone freeNew=new Memzone(busyNew.getEndID(),temp.getLength()-_applySize);   //产生的碎片
            free.remove(tempoint);    //移出原区域
            free.add(freeNew);  //加入新区域
        }
        return canFound;
    }
    
    void userApply(){
        Scanner input=new Scanner(System.in);
        System.out.println("Please enter the process name:");
        String temp=input.next();
        System.out.println("Please enter the applySize:");
        int tempI=input.nextInt();
        boolean tempB=apply(tempI, temp);
        if (tempB) {
           System.out.println("成功找到符合要求的区域"); 
        } else {
           System.out.println("没有找到符合要求的区域");
        }
    }
    
    void release(String _processName){
        boolean canFound=false;
        int tempBusy=-1,tempFree;
        for (int i = 0; i < busy.size(); i++) {     //根据给的进程名找出busy队列中的进程区域
            Memzone busyT=(Memzone)busy.get(i);
            if (busyT.getProcessName() == null ? _processName == null : busyT.getProcessName().equals(_processName)) {
                System.out.println("找到进程"+_processName);canFound=true;
                tempBusy=i;
            }
        }
        if (!canFound) {
            System.out.println("找不到符合的进程");
        }else{
            Memzone busyT=(Memzone)busy.get(tempBusy);
            int InitPoint = -1,EndPoint = -1; //标志指针
            boolean InitConect=false,EndConect=false;  //0表示没有空闲区与它相连，1表示前面有空闲区和它相连，2表示后面有空闲区和它相连，3表示两面都有空闲区相连
            Memzone newMemzone = null; //变量，新存储区指针
            for (int i = 0; i < free.size(); i++) {     //遍历空闲区队列
                Memzone freeT=(Memzone)free.get(i);
                if (busyT.getInitID()==freeT.getEndID()) {
                    InitConect=true;
                    InitPoint=i;
                }
            }            
            for (int i = 0; i < free.size(); i++) {
                Memzone freeT=(Memzone)free.get(i);
                if (busyT.getEndID()==freeT.getInitID()) {
                    EndConect=true;
                    EndPoint=i;
                }               
            }
            if (InitConect&&!EndConect) {
                newMemzone=new Memzone(((Memzone)free.get(InitPoint)).getInitID(),((Memzone)free.get(InitPoint)).getLength()+busyT.getLength() );
                free.remove(InitPoint);
            }else
            if (!InitConect&&EndConect) {
                newMemzone=new Memzone(busyT.getInitID(),((Memzone)free.get(EndPoint)).getLength()+busyT.getLength() );
                free.remove(EndPoint);
            }else
            if (InitConect&&EndConect) {
                newMemzone=new Memzone(((Memzone)free.get(InitPoint)).getInitID(),((Memzone)free.get(InitPoint)).getLength()+((Memzone)free.get(EndPoint)).getLength()+busyT.getLength());
                free.remove(EndPoint);
                free.remove(InitPoint);
            }else{
                newMemzone=busyT;
            }
            busy.remove(tempBusy);
            newMemzone.changeStatus();
            free.add(newMemzone);
        }
    }   
    
    void userRealse(){
        Scanner input=new Scanner(System.in);
        System.out.println("Please enter the process name:");
        release(input.next());
    }
    
    void display(){
        
        if (busy.isEmpty()) {
            System.out.println("任务区无进程运行");
        } else {
            System.out.println("任务区");
            for (int i = 0; i < busy.size(); i++) {
            System.out.println(((Memzone)busy.get(i)).toString());
            }            
        }
        
        if (free.isEmpty()) {
            System.out.println("无区域空闲");
            }else {
                System.out.println("空闲区");
                for (int i = 0; i < free.size(); i++) {
                System.out.println(((Memzone)free.get(i)).toString());
            }
        }
        System.out.println("");
    }
    
    void clear(){
        if (!busy.isEmpty()) {
            busy.clear();
            free.clear();
            total=new Memzone(0, 100);   //初始化一个从0开始，长度为100的空间
            free.add(total);  
            System.out.println("以终止所有程序运行");
        }
    }

}
