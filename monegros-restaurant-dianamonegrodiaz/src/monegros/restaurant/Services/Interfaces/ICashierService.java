package monegros.restaurant.services.interfaces;

import java.util.Optional;

import monegros.restaurant.entities.Cashier;

public interface ICashierService {
	Optional<Cashier> insert(Cashier cashier);
	Optional<Cashier> findById(Long id);
}
