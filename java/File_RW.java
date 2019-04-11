/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package file_rw;

import java.io.*;
import java.util.Scanner;

/**
 *
 * @author NirvanaLFR
 */
public class File_RW{

    public static void main(String[] args) {
        // TODO code application logic here
        File_RW frw=new File_RW();
        frw.run();
    }
    
    public void run() {
        // TODO code application logic here
        BufferedReader rd=openFile();
        try{
            
            PrintWriter pw=new PrintWriter(new FileWriter("lifurong.txt"));
            while(true){
                String line=rd.readLine();
                if(line==null) break;
                //System.out.println("Read Line:["+line+"]");
                System.out.println("Copying Line:["+line+"]");
                pw.println(line);
            }
            rd.close();
            pw.close();
        }catch(IOException ex){
            System.out.println("Something wrong");
        }
    }
    
    private BufferedReader openFile(){
        BufferedReader rd=null;
        Scanner input=new Scanner(System.in);
        while(rd==null){
            System.out.println("请输入想要打开并拷贝的文件名：（正确答案为students.txt）");
            try{
                String fileName=input.next();
                rd=new BufferedReader(new FileReader(fileName));
            }catch(IOException ex){
                System.out.println("Nice try punk.  The file does not exist");
            }
        }
        return rd;
    }
    
}
