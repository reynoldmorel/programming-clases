package monegros.restaurant.entities;

import java.util.List;

public class Chef extends Employee {
	private List<Order> ordersToCook;
	private int experience;
    public Chef() {
        super();
        
    }

    public Chef(Long id) {
        super(id);
    }

	public List<Order> getOrdersToCook() {
		return ordersToCook;
	}

	public void setOrdersToCook(List<Order> ordersToCook) {
		this.ordersToCook = ordersToCook;
	}

	public int getExperience() {
		return experience;
	}

	public void setExperience(int experience) {
		this.experience = experience;
	}
    
}
