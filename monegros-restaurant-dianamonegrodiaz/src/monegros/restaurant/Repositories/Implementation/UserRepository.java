package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.User;
import monegros.restaurant.entities.repository.IUserRepository;

public class UserRepository implements IUserRepository{
	private final Set<User> myUsers = new HashSet<>();

    @Override
    public Optional<User> insert(User user) {
        user.setId(Instant.now().toEpochMilli());
        this.myUsers.add(user);
        return Optional.of(user);
    }

    @Override
    public Optional<User> update(User user) {
        User existing =myUsers.stream()
                .filter(c -> c.equals(user))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The User you are trying to update does not exist"));

        existing.setAddress(user.getAddress());
        existing.setAge(user.getAge());
        existing.setName(user.getName());
        existing.setLastName(user.getLastName());
        existing.setPhone(user.getPhone());
        existing.setIdentification(user.getIdentification());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        User userToDelete = new User(id);
        myUsers.removeIf(c -> c.equals(userToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<User> findById(Long id) {

    	User existing = myUsers.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The User you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
