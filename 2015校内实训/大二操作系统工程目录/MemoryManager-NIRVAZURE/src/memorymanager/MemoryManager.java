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
public class MemoryManager {
    

    static boolean demoMenuB=true;     //boolean变量，是否展示菜单
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //主函数准备工作，构建输入器和控制器
        Control demoControler=new Control();
        Scanner input=new Scanner(System.in);
        //初始化操作
        init(demoControler);
        demoControler.display();
        System.out.println("输入0进入菜单");
        int a=input.nextInt();
        if(a==0){
            do {    
                menuDemo();
                int p=input.nextInt();
                a=menuOperate(demoControler,p);    
            } while (a!=-1);
        }        
    }

    static int menuOperate(Control _demoControl,int _a){
        switch(_a){
            case 0:demoMenuB=true;break;
            case 1:_demoControl.userApply();demoMenuB=false;break;
            case 2:_demoControl.userRealse();demoMenuB=false;break;
            case 3:_demoControl.display();demoMenuB=false;break;
            case 4:_demoControl.clear();demoMenuB=false;break;
            case 5:init(_demoControl);demoMenuB=false;break;
            default:_a =-1;System.out.println("Demo end");break;
        }       
        return _a;
    }
    
    static void menuDemo(){
        if (demoMenuB) {
            System.out.println("Please enter your operation:");
            System.out.println("1-Apply for a memoral zone");
            System.out.println("2-Release The Process");
            System.out.println("3-Display the occasion");
            System.out.println("4-Clear the busyzone");
            System.out.println("5-Initiate the workspace");
            System.out.println("others numbers to exit");            
        }
    }
    
    private static void init(Control _demoControl) {
        _demoControl.apply(30, "p1");
        _demoControl.apply(40, "p2");
        System.out.println("初始化成功");
    }
    
}
