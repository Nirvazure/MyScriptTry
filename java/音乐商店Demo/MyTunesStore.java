/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author NirvanaLFR
 */
public class MyTunesStore {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        MyTunesStore myStore=new MyTunesStore();
        
        while(true){
            int selection=getSelection();
            if(selection==QUIT) break;
            switch(selection){
                case LIST_SONGS:
                    myStore.listSongs();
                    break;
                case LIST_ALBUMS:
                    myStore.listAlbums();
                    break;  
                case ADD_SONG:
                    myStore.addSong();
                    break;
                case ADD_ALBUM:
                    myStore.addAlbum();
                    break;   
                case LIST_SONGS_IN_ABLUM:
                    myStore.listSongsInAlbum();
                    break;
                case UPDATE_SONG_PRICE:
                    myStore.updateSongPrice();
                    break;                       
            }
        }
    }
    
    private static int getSelection(){
        System.out.println();
        System.out.println("PLEASE ENTER THE SELECTION（0 TO QUIT）");
        System.out.println("1. LIST ALL SONGS");
        System.out.println("2. LIST ALL ABLUMS");
        System.out.println("3. ADD SONG TO STORE");
        System.out.println("4. ADD ABLUM TO STORE");
        System.out.println("5. LIST SONGS IN ABLUM");
        System.out.println("6. UPDATE SONG'S PRICE");  
        Scanner input=new Scanner(System.in);
        System.out.printf("SELECT: ");  
        return input.nextInt();
    }
    
    private static final int QUIT=0;
    private static final int LIST_SONGS=1;
    private static final int LIST_ALBUMS=2;
    private static final int ADD_SONG=3;
    private static final int ADD_ALBUM=4;
    private static final int LIST_SONGS_IN_ABLUM=5;
    private static final int UPDATE_SONG_PRICE=6;

    private void listSongs() {
        System.out.println("ALL SONGS IN THE STORE");
        for(int i=0;i<songs.size();i++){
            System.out.println(songs.get(i).toString());
        }
    }

    private void listAlbums() {
        System.out.println("ALL ALBUMS IN THE STORE");
        Iterator<String> albumIt=albums.keySet().iterator();
        while(albumIt.hasNext()){
            System.out.println(albums.get(albumIt.next()).toString());            
        }
    }

    private Song addSong() {
        Scanner input=new Scanner(System.in);
        System.out.println("ENTER THE SONG'S NAME");
        String name=input.next();
        if(name.equals("")) return null;
        System.out.println("ENTER THE SONG'S ARTIST");
        String artist=input.next();
        int songIndex=findSong(name,artist);
        if(songIndex!=-1){
            System.out.println("THE SONG'S IS ALREADY IN THE STORE");
            return songs.get(songIndex);
        }else{
            System.out.println("ENTER THE SONG'S PRICE");            
            double price=input.nextDouble();
            Song newSong=new Song(name,artist,price);
            songs.add(newSong);
            System.out.println("THE SONG'S IS ADDED IN THE STORE");
            return newSong;
        }
    }

    private void addAlbum() {
        Scanner input=new Scanner(System.in);
        System.out.println("ENTER THE ALBUN'S NAME");
        String name=input.next();
        
        if(albums.containsKey(name)){
            System.out.println("THE ALBUM IS ALREADY IN THE STORE");            
        }else{
            System.out.println("ENTER THE ALBUM'S ARTIST");
            String artist=input.next();   
            Album album=new Album(name,artist);
            albums.put(name, album);
            
            while(true){
                Song song=addSong();
                if(song==null) break;   //没有终止标记
                album.addSong(song);
            }
            System.out.println("THE ALBUM IS ADDED IN THE STORE");    
        }
    }

    private void listSongsInAlbum() {
        Scanner input=new Scanner(System.in);
        System.out.println("ENTER THE ALBUN'S NAME");
        String name=input.next();
        
        if(albums.containsKey(name)){
            Iterator<Song> it=albums.get(name).getSongs();
            System.out.println(name+" CONTAINS THE FOLLOWING SONGS:");
            while(it.hasNext()){
                Song song=it.next();
                System.out.println(song.toString());
            }
        }else{
            System.out.println("NO ALBUM BY THE NAME IN THE STORE");          
        }
    }

    private void updateSongPrice() {
        Scanner input=new Scanner(System.in);
        System.out.println("ENTER THE SONG'S NAME");
        String name=input.next();
        System.out.println("ENTER THE SONG'S ARTIST");
        String artist=input.next();
        int songIndex=findSong(name,artist);
        if(songIndex==-1){
            System.out.println("THE SONG'S IS NOT IN THE STORE");
        }else{
            System.out.println("ENTER THE SONG'S PRICE");            
            double price=input.nextDouble();
            double oldPrice=songs.get(songIndex).getSongPrice();
            songs.get(songIndex).setSongPrice(price);
            System.out.println("PRICE OF"+name+"IS UPDATED  THE OLD IS:"+oldPrice+" THE NEW IS"+songs.get(songIndex).getSongPrice());  
        }
    }
    
    private int findSong(String name,String artist){
        int index=-1;
        for (int i = 0; i <songs.size(); i++) {
            if(songs.get(i).getSongName().equals(name)&&songs.get(i).getSongArtist().equals(artist)){
                index=i;
                break;
            }
        }
        return index;
    }
    
    //专辑由HashMap保存
    private HashMap<String,Album> albums=new HashMap<String,Album>();
    //ArrayList保存售卖的单曲
    private ArrayList<Song> songs=new ArrayList<Song>();
}
