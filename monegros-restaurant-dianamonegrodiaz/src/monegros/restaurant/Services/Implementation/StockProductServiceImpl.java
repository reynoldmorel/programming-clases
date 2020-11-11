package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.StockProduct;
import monegros.restaurant.entities.repository.IStockProductRepository;
import monegros.restaurant.services.interfaces.IStockProductService;

public class StockProductServiceImpl implements IStockProductService{
private final IStockProductRepository stockProductRepository;
	
	public StockProductServiceImpl(IStockProductRepository stockProductRepository) {
		this.stockProductRepository=stockProductRepository;
	}
	@Override
	public Optional<StockProduct> insert(StockProduct cashier) {
		return this.stockProductRepository.insert(cashier);
	}
	@Override
	public Optional<StockProduct> findById(Long id) {
		return this.stockProductRepository.findById(id);
	}
}
