package monegros.restaurant.entities.repository.implementation;

import monegros.restaurant.entities.repository.IProductRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Product;

public class ProductRepository implements IProductRepository{
    private final Set<Product> myProducts = new HashSet<>();

    @Override
    public Optional<Product> insert(Product product) {
        product.setId(Instant.now().toEpochMilli());
        this.myProducts.add(product);
        
        return Optional.of(product);
    }
    @Override
    public Optional<Product> update(Product product) {
    	Product existing = myProducts.stream()
                .filter(c -> c.equals(product))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Product you are trying to update does not exist"));

        existing.setMeasureUnit(product.getMeasureUnit());
        existing.setName(product.getName());
        existing.setPrice(product.getPrice());
        
        return Optional.of(existing);
    }
    @Override
    public Optional<Product> findById(Long id) {
    	Product existing = myProducts.stream()
                    .filter(c -> c.getId().equals(id))
                    .findFirst()
                    .orElseThrow(() -> new IllegalArgumentException("The Product you are trying to find does not exist"));

            return Optional.of(existing);
    }

    @Override
    public Optional<Boolean> delete(Long id) {
    	Product productToDelete = new Product(id);
        myProducts.removeIf(c -> c.equals(productToDelete));

        return Optional.of(Boolean.TRUE);
    }
}