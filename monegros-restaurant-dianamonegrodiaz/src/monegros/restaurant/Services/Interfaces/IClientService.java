package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Client;

public interface IClientService {
	Optional<Client> insert(Client client);
	Optional<Client> findById(Long id);
}
