package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Menu;
import monegros.restaurant.entities.repository.IMenuRepository;
import monegros.restaurant.services.interfaces.IMenuService;

public class MenuServiceImpl implements IMenuService {
	private final IMenuRepository menuRepository;

	public MenuServiceImpl(IMenuRepository menuRepository) {
		this.menuRepository = menuRepository;
	}

	@Override
	public Optional<Menu> insert(Menu menu) {
		return this.menuRepository.insert(menu);
	}

	@Override
	public Optional<Menu> findById(Long id) {
		return this.menuRepository.findById(id);
	}
}
