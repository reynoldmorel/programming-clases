package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Product;
import monegros.restaurant.entities.repository.IProductRepository;
import monegros.restaurant.services.interfaces.IProductService;

public class ProductServiceImpl implements IProductService{
private final IProductRepository productRepository;
	
	public ProductServiceImpl(IProductRepository productRepository) {
		this.productRepository=productRepository;
	}
	@Override
	public Optional<Product> insert(Product product) {
		return this.productRepository.insert(product);
	}
	@Override
	public Optional<Product> findById(Long id) {
		return this.productRepository.findById(id);
	}
}
