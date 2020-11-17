package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.User;

public interface IUserService {
	Optional<User> insert(User user);

	Optional<User> findById(Long id);
}
