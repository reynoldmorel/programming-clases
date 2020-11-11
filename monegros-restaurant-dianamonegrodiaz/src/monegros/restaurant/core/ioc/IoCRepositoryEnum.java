package monegros.restaurant.core.ioc;

public enum IoCRepositoryEnum {
	ORDER_REPOSITORY("orderRepository"),
    CASHIER_REPOSITORY("cashierRepository"),
	CHEF_REPOSITORY("chefRepository"),
	CLIENT_REPOSITORY("clientRepository"),
	EMPLOYEE_REPOSITORY("employeeRepository"),
	FINAL_PRODUCT_REPOSITORY("finalProductRepository"),
	MEASURE_UNIT_REPOSITORY("measumentUnitRepository"),
	MENU_ITEM_REPOSITORY("menuItemRepository"),
	MENU_REPOSITORY("menuRepository"),
	ORDER_DETAIL_REPOSITORY("orderDetailRepository"),
	PRODUCT_REPOSITORY("productRepository"),
	STOCK_PRODUCT_REPOSITORY("stockProductRepository"),
	STOCK_REPOSITORY("stockRepository"),
	USER_REPOSITORY("userRepository");
	
    private final String value;

    IoCRepositoryEnum(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}
