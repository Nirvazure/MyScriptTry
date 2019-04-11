/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mypcb;

import java.util.Scanner;

/**
 *
 * @author LiFeReal
 */
public class MyPCB {
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner input=new Scanner(System.in);
        
        Control controler=new Control();
        controler.loadInitProcess();
        ModelProcess p4=controler.create("oranfe", "as",4);
        controler.insert(p4);
        System.out.println("Press 0 to the Menu");
        controler.display();
        
        int a=input.nextInt();
        boolean b=true;
        if(a==0){
            do {                
                menuDemo(controler);
                int p=input.nextInt();
                a=menuOperate(controler, p);    
            } while (a!=-1);
        }
    }
    
    static int menuOperate(Control _c,int _a){
        System.out.println("Press 0 to Menu");
        
        switch(_a){
            case 0:_c.tmpboolean=true;break;
            case 1:_c.display();_c.tmpboolean=false;break;
            case 2:_c.newProcess();break;
            case 3:_c.menuBlock();break;
            case 4:_c.menuWakeup();_c.tmpboolean=false;break;
            case 5:_c.takeTurnDemo();_c.tmpboolean=false;break;
            case 6:_c.loadInitProcess();break;
            default:_a =-1;System.out.println("Demo end");break;
        }       
        return _a;
    }
    
    static void menuDemo(Control _c){
        if(_c.tmpboolean){
            System.out.println("Please enter your operation:");
            System.out.println("1-Display The readyList");
            System.out.println("2-Create The New Process");
            System.out.println("3-Block The New Process");
            System.out.println("4-Wake up The blocked Process");
            System.out.println("5-Take Turns");
            System.out.println("6-InitProcess");
            System.out.println("others numbers to exit");
        }
    }
    
}
