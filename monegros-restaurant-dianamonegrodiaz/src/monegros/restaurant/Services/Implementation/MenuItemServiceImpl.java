package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.MenuItem;
import monegros.restaurant.entities.repository.IMenuItemRepository;
import monegros.restaurant.services.interfaces.IMenuItemService;

public class MenuItemServiceImpl implements IMenuItemService{
private final IMenuItemRepository menuItemRepository;
	
	public MenuItemServiceImpl(IMenuItemRepository menuItemRepository) {
		this.menuItemRepository=menuItemRepository;
	}
	@Override
	public Optional<MenuItem> insert(MenuItem cashier) {
		return this.menuItemRepository.insert(cashier);
	}
	@Override
	public Optional<MenuItem> findById(Long id) {
		return this.menuItemRepository.findById(id);
	}
}
