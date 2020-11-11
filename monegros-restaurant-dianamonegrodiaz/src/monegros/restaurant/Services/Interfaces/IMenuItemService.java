package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.MenuItem;

public interface IMenuItemService {
	Optional<MenuItem> insert(MenuItem menuItem);

	Optional<MenuItem> findById(Long id);
}
