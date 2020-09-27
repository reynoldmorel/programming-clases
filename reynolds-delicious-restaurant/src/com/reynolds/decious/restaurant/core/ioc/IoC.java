package com.reynolds.decious.restaurant.core.ioc;

import com.reynolds.decious.restaurant.respositories.impl.CashierRepository;
import com.reynolds.decious.restaurant.respositories.impl.OrderRepository;

import java.util.HashMap;
import java.util.Map;

public final class IoC {
    private static IoC iocInstance = null;
    private final Map<String, Object> pool = new HashMap<>();

    private IoC() {
        this.insertReposInThePool(this.pool);
    }

    public static IoC getInstance() {
        if (iocInstance == null) {
            iocInstance = new IoC();
        }

        return iocInstance;
    }

    public <T> T getFromPool(IoCRepositoryEnum key) {
        return (T) pool.get(key.getValue());
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
    }
}
