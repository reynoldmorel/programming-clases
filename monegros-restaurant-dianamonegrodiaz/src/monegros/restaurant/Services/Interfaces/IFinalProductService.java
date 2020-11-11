package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.FinalProduct;

public interface IFinalProductService {
	Optional<FinalProduct> insert(FinalProduct finalProduct);
	Optional<FinalProduct> findById(Long id);
}
