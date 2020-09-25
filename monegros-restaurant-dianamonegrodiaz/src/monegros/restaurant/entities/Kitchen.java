package monegros.restaurant.entities;

import java.util.List;

public class Kitchen {
	private QueueOrders myOrdersQueue;
	private List<Chef> myChefs;
	public Kitchen() {
		super();
	}

	public QueueOrders getMyOrders() {
		return myOrdersQueue;
	}

	public void setMyOrders(QueueOrders myOrders) {
		this.myOrdersQueue = myOrders;
	}

	public List<Chef> getMyChefs() {
		return myChefs;
	}

	public void setMyChefs(List<Chef> myChefs) {
		this.myChefs = myChefs;
	}

	public void recieveNewOrder(Order myOrder) {
		// TODO Auto-generated method stub
		myOrdersQueue.addOrder(myOrder);
	}
}
