package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Stock;
import monegros.restaurant.entities.repository.IStockRepository;

public class StockRepository implements IStockRepository {
    private final Set<Stock> myStock = new HashSet<>();

    @Override
    public Optional<Stock> insert(Stock stock) {
        stock.setId(Instant.now().toEpochMilli());
        this.myStock.add(stock);
        return Optional.of(stock);
    }

    @Override
    public Optional<Stock> update(Stock stock) {
        Stock existing = myStock.stream()
                .filter(c -> c.equals(stock))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Stock you are trying to update does not exist"));

        existing.setName(stock.getName());
        existing.setStockProducts(stock.getStockProducts());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        Stock stockToDelete = new Stock(id);
        myStock.removeIf(c -> c.equals(stockToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<Stock> findById(Long id) {

    	Stock existing = myStock.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Stock you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
