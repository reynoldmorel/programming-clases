package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Menu;

public interface IMenuService {
	Optional<Menu> insert(Menu menu);
	Optional<Menu> findById(Long id);
}
