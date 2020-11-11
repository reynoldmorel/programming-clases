package monegros.restaurant.core.ioc;

public enum IoCServicesEnum {
	ORDER_SERVICE("orderService"),
    CASHIER_SERVICE("cashierService"),
	CHEF_SERVICE("chefService"),
	CLIENT_SERVICE("clientService"),
	EMPLOYEE_SERVICE("employeeService"),
	FINAL_PRODUCT_SERVICE("finalProductService"),
	MEASURE_UNIT_SERVICE("measumentUnitService"),
	MENU_ITEM_SERVICE("menuItemService"),
	MENU_SERVICE("menuService"),
	ORDER_DETAIL_SERVICE("orderDetailService"),
	PRODUCT_SERVICE("productService"),
	STOCK_PRODUCT_SERVICE("stockProductService"),
	STOCK_SERVICE("stockService"),
	USER_SERVICE("userService");
	
    private final String value;

    IoCServicesEnum(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}
