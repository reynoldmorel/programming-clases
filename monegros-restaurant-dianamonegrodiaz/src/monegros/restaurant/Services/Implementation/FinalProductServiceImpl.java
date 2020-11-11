package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.FinalProduct;
import monegros.restaurant.entities.repository.IFinalProductRepository;
import monegros.restaurant.services.interfaces.IFinalProductService;

public class FinalProductServiceImpl implements IFinalProductService {
	private final IFinalProductRepository finalProductRepository;

	public FinalProductServiceImpl(IFinalProductRepository finalProductRepository) {
		this.finalProductRepository = finalProductRepository;
	}

	@Override
	public Optional<FinalProduct> insert(FinalProduct finalProduct) {
		return this.finalProductRepository.insert(finalProduct);
	}

	@Override
	public Optional<FinalProduct> findById(Long id) {
		return this.finalProductRepository.findById(id);
	}
}
