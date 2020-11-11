package monegros.restaurant.core.ioc;

import java.util.HashMap;
import java.util.Map;
import monegros.restaurant.entities.repository.implementation.CashierRepository;
import monegros.restaurant.entities.repository.implementation.ChefRepository;
import monegros.restaurant.entities.repository.implementation.ClientRepository;
import monegros.restaurant.entities.repository.implementation.EmployeeRepository;
import monegros.restaurant.entities.repository.implementation.FinalProductRepository;
import monegros.restaurant.entities.repository.implementation.MeasureUnitRepository;
import monegros.restaurant.entities.repository.implementation.MenuItemRepository;
import monegros.restaurant.entities.repository.implementation.MenuRepository;
import monegros.restaurant.entities.repository.implementation.OrderDetailRepository;
import monegros.restaurant.entities.repository.implementation.OrderRepository;
import monegros.restaurant.entities.repository.implementation.ProductRepository;
import monegros.restaurant.entities.repository.implementation.StockProductRepository;
import monegros.restaurant.entities.repository.implementation.StockRepository;
import monegros.restaurant.entities.repository.implementation.UserRepository;
import monegros.restaurant.services.implementation.CashierServiceImpl;
import monegros.restaurant.services.implementation.ChefServiceImpl;
import monegros.restaurant.services.implementation.ClientServiceImpl;
import monegros.restaurant.services.implementation.EmployeeServiceImpl;
import monegros.restaurant.services.implementation.FinalProductServiceImpl;
import monegros.restaurant.services.implementation.MeasureUnitServiceImpl;
import monegros.restaurant.services.implementation.MenuItemServiceImpl;
import monegros.restaurant.services.implementation.MenuServiceImpl;
import monegros.restaurant.services.implementation.OrderDetailServiceImpl;
import monegros.restaurant.services.implementation.OrderServiceImpl;
import monegros.restaurant.services.implementation.ProductServiceImpl;
import monegros.restaurant.services.implementation.StockProductServiceImpl;
import monegros.restaurant.services.implementation.StockServiceImpl;
import monegros.restaurant.services.implementation.UserServiceImpl;

public class IoC {
	private static IoC iocInstance;
	private final Map<String,Object> myMap = new HashMap<>();
	
	private IoC() {
        this.insertReposInThePool(this.myMap);
        this.insertServicesInThePool(this.myMap);
    }

	public static IoC getInstance() {
        if (iocInstance == null) {
            iocInstance = new IoC();
        }
        return iocInstance;
    }

    public <O> O getFromPool(String key) {
        return (O) myMap.get(key);
    }

    private void insertReposInThePool(Map<String, Object> pool) {
        pool.put(
                IoCRepositoryEnum.CASHIER_REPOSITORY.getValue(),
                new CashierRepository()
        );

        pool.put(
                IoCRepositoryEnum.ORDER_REPOSITORY.getValue(),
                new OrderRepository()
        );
        pool.put(
                IoCRepositoryEnum.CHEF_REPOSITORY.getValue(),
                new ChefRepository()
        );
        pool.put(
                IoCRepositoryEnum.CLIENT_REPOSITORY.getValue(),
                new ClientRepository()
        );
        pool.put(
                IoCRepositoryEnum.EMPLOYEE_REPOSITORY.getValue(),
                new EmployeeRepository()
        );
        pool.put(
                IoCRepositoryEnum.FINAL_PRODUCT_REPOSITORY.getValue(),
                new FinalProductRepository()
        );
        pool.put(
                IoCRepositoryEnum.MEASURE_UNIT_REPOSITORY.getValue(),
                new MeasureUnitRepository()
        );
        pool.put(
                IoCRepositoryEnum.MENU_ITEM_REPOSITORY.getValue(),
                new MenuItemRepository()
        );
        pool.put(
                IoCRepositoryEnum.MENU_REPOSITORY.getValue(),
                new MenuRepository()
        );
        pool.put(
                IoCRepositoryEnum.ORDER_DETAIL_REPOSITORY.getValue(),
                new OrderDetailRepository()
        );
        pool.put(
                IoCRepositoryEnum.PRODUCT_REPOSITORY.getValue(),
                new ProductRepository()
        );
        pool.put(
                IoCRepositoryEnum.STOCK_PRODUCT_REPOSITORY.getValue(),
                new StockProductRepository()
        );
        pool.put(
                IoCRepositoryEnum.STOCK_REPOSITORY.getValue(),
                new StockRepository()
        );
        pool.put(
                IoCRepositoryEnum.USER_REPOSITORY.getValue(),
                new UserRepository()
        );
    }
    
    private void insertServicesInThePool(Map<String, Object> pool) {
        pool.put(
                IoCServicesEnum.CASHIER_SERVICE.getValue(),
                new CashierServiceImpl(getFromPool(IoCRepositoryEnum.CASHIER_REPOSITORY.getValue()))
        );
        pool.put(
        		 IoCServicesEnum.ORDER_SERVICE.getValue(),
                 new OrderServiceImpl(getFromPool(IoCRepositoryEnum.ORDER_REPOSITORY.getValue()))
        );
        pool.put(
        		 IoCServicesEnum.CHEF_SERVICE.getValue(),
                 new ChefServiceImpl(getFromPool(IoCRepositoryEnum.CHEF_REPOSITORY.getValue()))
        );
        pool.put(
        		 IoCServicesEnum.CLIENT_SERVICE.getValue(),
                 new ClientServiceImpl(getFromPool(IoCRepositoryEnum.CLIENT_REPOSITORY.getValue()))
        );
        pool.put(
        		 IoCServicesEnum.EMPLOYEE_SERVICE.getValue(),
                 new EmployeeServiceImpl(getFromPool(IoCRepositoryEnum.EMPLOYEE_REPOSITORY.getValue()))
        );
        pool.put(
        		 IoCServicesEnum.FINAL_PRODUCT_SERVICE.getValue(),
                 new FinalProductServiceImpl(getFromPool(IoCRepositoryEnum.FINAL_PRODUCT_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.MEASURE_UNIT_SERVICE.getValue(),
                new MeasureUnitServiceImpl(getFromPool(IoCRepositoryEnum.MEASURE_UNIT_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.MENU_ITEM_SERVICE.getValue(),
                new MenuItemServiceImpl(getFromPool(IoCRepositoryEnum.MENU_ITEM_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.MENU_SERVICE.getValue(),
                new MenuServiceImpl(getFromPool(IoCRepositoryEnum.MENU_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.ORDER_DETAIL_SERVICE.getValue(),
                new OrderDetailServiceImpl(getFromPool(IoCRepositoryEnum.ORDER_DETAIL_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.PRODUCT_SERVICE.getValue(),
                new ProductServiceImpl(getFromPool(IoCRepositoryEnum.PRODUCT_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.STOCK_PRODUCT_SERVICE.getValue(),
                new StockProductServiceImpl(getFromPool(IoCRepositoryEnum.STOCK_PRODUCT_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.STOCK_SERVICE.getValue(),
                new StockServiceImpl(getFromPool(IoCRepositoryEnum.STOCK_REPOSITORY.getValue()))
        );
        pool.put(
        		IoCServicesEnum.USER_SERVICE.getValue(),
                new UserServiceImpl(getFromPool(IoCRepositoryEnum.USER_REPOSITORY.getValue()))
        );
    }
}
