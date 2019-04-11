/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package data;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author hrmthw
 */
public class Program {

    private final String programName;
    private final String cmd;

    public String getProgramName() {
        return programName;
    }

    public String getCmd() {
        return cmd;
    }

    public Program(String name) throws FileNotFoundException {
        programName = name;
        Scanner fileInput;
        fileInput = new Scanner(new File("program/" + programName));
        cmd = fileInput.nextLine();
        fileInput.close();
    }
}
