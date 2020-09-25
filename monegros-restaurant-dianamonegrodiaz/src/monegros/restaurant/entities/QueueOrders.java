package monegros.restaurant.entities;

import java.util.LinkedList;
import java.util.Queue;

public class QueueOrders {
	private Queue<Order> myOrders=new LinkedList<Order>();

	public QueueOrders() {
		super();
	}

	public QueueOrders(Queue<Order> myOrders) {
		super();
		this.myOrders = myOrders;
	}

	public Queue<Order> getMyOrders() {
		return myOrders;
	}

	public void setMyOrders(Queue<Order> myOrders) {
		this.myOrders = myOrders;
	}

	public void addOrder(Order myOrder) {
		// TODO Auto-generated method stub
		this.myOrders.add(myOrder);
	}
	public void removeTopOrder() {
		// TODO Auto-generated method stub
		this.myOrders.poll();
	}
	public Order peekTopOrder() {
		return this.myOrders.peek();
	}

	 
	
}
