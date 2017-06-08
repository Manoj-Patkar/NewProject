package com.examples;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class City {
	int v=-1;
	private HashMap<Integer,LinkedList<Integer>> adj;
	
	public City(int v){
		//this.v=v;
		adj=new HashMap<Integer,LinkedList<Integer>>();
	}
	
	public void addEdge(int v,int w){
		if(adj.get(v)==null)
		{
			LinkedList<Integer> linkList=new LinkedList<Integer>();
			linkList.add(w);
			adj.put(v, linkList);
		}
		else{
			LinkedList<Integer> linkList=adj.get(v);
			linkList.add(w);
			adj.put(v, linkList);
		}
	}
	
	
	public boolean Dps(boolean visited[],int node,int dest){
		
		if(visited[dest]==true)
			return true;
		
		visited[node]=true;
		
		System.out.print("-->"+node);
		Iterator<Integer> it=null;
		
		if(adj.get(node)!= null )
	     it=adj.get(node).listIterator();
		
		if(it!=null){
		while(it.hasNext()){
			int next=it.next();
			if(!visited[next])
				Dps(visited,next,dest);
		}
		}
		return false;
		
	}
	
	public static void main(String[] args){
		City city=new City(15);
		city.addEdge(1, 2);
		city.addEdge(1, 3);
		city.addEdge(2, 4);
		city.addEdge(2, 3);
		city.addEdge(2, 5);
		city.addEdge(3, 4);
		city.addEdge(4, 5);
		city.addEdge(5, 6);
		city.addEdge(6, 7);
		city.addEdge(2, 9);
		city.addEdge(9, 10);
		boolean visited[]=new boolean[15];
		city.Dps(visited,1,7);
		
	/*	for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				
				if(city.Dps(visited,i,j)){
					
				}
			}
			
		}*/
		
		System.out.println();
		System.out.println(city.v);
		
		
	}

}
