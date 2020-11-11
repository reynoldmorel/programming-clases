package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Cashier;
import monegros.restaurant.entities.repository.ICashierRepository;
import monegros.restaurant.services.interfaces.ICashierService;

public class CashierServiceImpl implements ICashierService {
	private final ICashierRepository cashierRepository;

	public CashierServiceImpl(ICashierRepository cashierRepository) {
		this.cashierRepository = cashierRepository;
	}

	@Override
	public Optional<Cashier> insert(Cashier cashier) {
		return this.cashierRepository.insert(cashier);
	}

	@Override
	public Optional<Cashier> findById(Long id) {
		return this.cashierRepository.findById(id);
	}
}
