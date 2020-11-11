package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.repository.IChefRepository;
import monegros.restaurant.services.interfaces.IChefService;
import monegros.restaurant.entities.Chef;

public class ChefServiceImpl implements IChefService{
	private final IChefRepository chefRepository;
	
	public ChefServiceImpl(IChefRepository chefRepository) {
		this.chefRepository = chefRepository;
	}
	@Override
	public Optional<Chef> findById(Long id) {
		return this.chefRepository.findById(id);
	}
	@Override
	public Optional<Chef> insert(Chef chef) {
		return this.chefRepository.insert(chef);
	}
}
