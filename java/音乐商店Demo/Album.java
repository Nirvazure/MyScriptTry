/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author NirvanaLFR
 */
public class Album {
    
    public Album(String name,String artist){
        title=name;
        this.artist=artist;
    }
    
    public void addSong(Song song){
        songs.add(song);
    }
    
    public Iterator<Song> getSongs(){
        return songs.iterator();
    }
    
    public String toString(){
        return("\""+title+"\" by "+artist);
    }
    
    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }
    
    private String title;
    private String artist;
    private ArrayList<Song> songs=new ArrayList<Song>();
    
}
