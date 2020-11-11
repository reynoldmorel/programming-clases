package monegros.restaurant.services.interfaces;

import java.util.Optional;

import monegros.restaurant.entities.Chef;

public interface IChefService {
	Optional<Chef> insert(Chef chef);
	Optional<Chef> findById (Long id);
}
