package monegros.restaurant.entities.repository.implementation;

import monegros.restaurant.entities.repository.IFinalProductRepository;
import monegros.restaurant.entities.FinalProduct;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class FinalProductRepository implements IFinalProductRepository {
	private final Set<FinalProduct> myFinalProducts= new HashSet<>();
	
	@Override
    public Optional<FinalProduct> insert(FinalProduct finalProduct) {
        finalProduct.setId(Instant.now().toEpochMilli());
        this.myFinalProducts.add(finalProduct);
        return Optional.of(finalProduct);
    }
	
	@Override
    public Optional<FinalProduct> update(FinalProduct finalProduct) {
        FinalProduct existing = myFinalProducts.stream()
                .filter(c -> c.equals(finalProduct))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Final Product you are trying to update does not exist"));

        existing.setMeasureUnit(finalProduct.getMeasureUnit());
        existing.setPrice(finalProduct.getPrice());
        existing.setName(finalProduct.getName());
        existing.setProducts(finalProduct.getProducts());

        return Optional.of(existing);
    }
	@Override
	public Optional<FinalProduct> findById(Long id) {

    	FinalProduct existing = myFinalProducts.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Final Product you are trying to find does not exist"));

        return Optional.of(existing);
    }
	@Override
    public Optional<Boolean> delete(Long id) {
        FinalProduct finalProductToDelete = new FinalProduct(id);
        myFinalProducts.removeIf(c -> c.equals(finalProductToDelete));
        return Optional.of(Boolean.TRUE);
    }
}
