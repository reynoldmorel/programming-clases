package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Stock;

public interface IStockService {
	Optional<Stock> insert(Stock stock);

	Optional<Stock> findById(Long id);
}
