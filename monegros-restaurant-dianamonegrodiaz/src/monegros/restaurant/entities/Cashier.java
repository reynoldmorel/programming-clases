package monegros.restaurant.entities;

public class Cashier extends Employee {
	private Order newOrder;
	private Kitchen myKitchen;
    public Cashier() {
        super();
    }

    public Cashier(Long id) {
        super(id);
    }

	public Order getNewOrder() {
		return newOrder;
	}

	private void setNewOrder(Order newOrder) {
		this.newOrder = newOrder;
	}

	public Kitchen getMyKitchen() {
		return myKitchen;
	}

	public void setMyKitchen(Kitchen myKitchen) {
		this.myKitchen = myKitchen;
	}

	public void recieveOrder(Order myOrder) {
		// TODO Auto-generated method stub
		myOrder.setStatus("Preparing");
		setNewOrder(myOrder);
		sendOrderToKitchen(myOrder);
	}
	public void sendOrderToKitchen(Order myOrder) {
		this.myKitchen.recieveNewOrder(myOrder);
	}
	
}
