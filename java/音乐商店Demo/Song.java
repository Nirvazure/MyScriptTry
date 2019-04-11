/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author NirvanaLFR
 */
public class Song {
    
    public Song(String title,String artist,double price){
        this.title=title;
        this.artist=artist;
        this.price=price;
    }
    
    public String getSongName(){
        return title;
    }
    
    public String getSongArtist(){
        return artist;
    }
    
    public double getSongPrice(){
        return price;
    }
    
    public void setSongPrice(double newPrice){
        price=newPrice;
    }
    
    public String toString(){
        return ("\""+title+"\"by"+artist+"cost $"+price);
    }
    
    private String title;
    private String artist;
    private double price;
    
}
