package monegros.restaurant.services.implementation;

import java.util.Collection;
import java.util.Optional;
import monegros.restaurant.entities.Cashier;
import monegros.restaurant.entities.repository.ICashierRepository;
import monegros.restaurant.services.interfaces.ICashierService;

public class CashierServiceImpl implements ICashierService {
	private final ICashierRepository cashierRepository;
	private long id;

	public CashierServiceImpl(ICashierRepository cashierRepository) {
		this.cashierRepository = cashierRepository;
	}

	@Override
	public Optional<Cashier> insert(Cashier cashier) {
		cashier.setId(this.id);
		this.id++;
		return this.cashierRepository.insert(cashier);
	}

	@Override
	public Optional<Cashier> findById(Long id) {
		return this.cashierRepository.findById(id);
	}

	@Override
	public Optional<Boolean> delete(Long id) {
		return cashierRepository.delete(id);
	}

	@Override
	public Optional<Cashier> update(Cashier cashier) {
		return cashierRepository.update(cashier);
	}

	@Override
	public Collection<Cashier> findAll() {
		return cashierRepository.findAll();
	}
}
