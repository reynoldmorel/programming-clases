package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.StockProduct;

public interface IStockProductService {
	Optional<StockProduct> insert(StockProduct cashier);
	Optional<StockProduct> findById(Long id);
}
