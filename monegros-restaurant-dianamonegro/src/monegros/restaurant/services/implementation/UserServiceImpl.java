package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.User;
import monegros.restaurant.entities.repository.IUserRepository;
import monegros.restaurant.services.interfaces.IUserService;

public class UserServiceImpl implements IUserService {
	private final IUserRepository userRepository;

	public UserServiceImpl(IUserRepository userRepository) {
		this.userRepository = userRepository;
	}

	@Override
	public Optional<User> insert(User user) {
		return this.userRepository.insert(user);
	}

	@Override
	public Optional<User> findById(Long id) {
		return this.userRepository.findById(id);
	}
}
