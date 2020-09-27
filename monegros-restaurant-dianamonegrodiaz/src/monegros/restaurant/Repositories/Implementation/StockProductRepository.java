package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.StockProduct;
import monegros.restaurant.entities.repository.IStockProductRepository;

public class StockProductRepository implements IStockProductRepository{
    private final Set<StockProduct> myStockProducts = new HashSet<>();

    @Override
    public Optional<StockProduct> insert(StockProduct stockProduct) {
        stockProduct.setId(Instant.now().toEpochMilli());
        this.myStockProducts.add(stockProduct);
        return Optional.of(stockProduct);
    }

    @Override
    public Optional<StockProduct> update(StockProduct stockProduct) {
        StockProduct existing = myStockProducts.stream()
                .filter(c -> c.equals(stockProduct))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Stock Product you are trying to update does not exist"));

        existing.setMeasureUnit(stockProduct.getMeasureUnit());
        existing.setProduct(stockProduct.getProduct());
        existing.setQuantity(stockProduct.getQuantity());
        existing.setStock(stockProduct.getStock());
        
        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        StockProduct stockProductToDelete = new StockProduct(id);
        myStockProducts.removeIf(c -> c.equals(stockProductToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<StockProduct> findById(Long id) {

    	StockProduct existing = myStockProducts.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Stock Product you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
