package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Client;
import monegros.restaurant.entities.repository.IClientRepository;
import monegros.restaurant.services.interfaces.IClientService;

public class ClientServiceImpl implements IClientService{
	private final IClientRepository clientRepository;
	
	public ClientServiceImpl(IClientRepository clientRepository) {
		this.clientRepository=clientRepository;
	}
	@Override
	public Optional<Client> insert(Client client) {
		return this.clientRepository.insert(client);
	}
	@Override
	public Optional<Client> findById(Long id) {
		return this.clientRepository.findById(id);
	}
}
