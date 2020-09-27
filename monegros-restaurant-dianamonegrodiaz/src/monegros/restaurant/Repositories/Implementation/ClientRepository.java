package monegros.restaurant.entities.repository.implementation;

import monegros.restaurant.entities.repository.IClientRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Client;

public class ClientRepository implements IClientRepository{
	private final Set<Client> myClients = new HashSet<>();

    @Override
    public Optional<Client> insert(Client client) {
        client.setId(Instant.now().toEpochMilli());
        this.myClients.add(client);
        return Optional.of(client);
    }

    @Override
    public Optional<Client> update(Client client) {
        Client existing = myClients.stream()
                .filter(c -> c.equals(client))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Client you are trying to update does not exist"));

        existing.setAddress(client.getAddress());
        existing.setAge(client.getAge());
        existing.setName(client.getName());
        existing.setLastName(client.getLastName());
        existing.setPhone(client.getPhone());
        existing.setCode(client.getCode());
        existing.setIdentification(client.getIdentification());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        Client clientToDelete = new Client(id);
        myClients.removeIf(c -> c.equals(clientToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<Client> findById(Long id) {
    	Client existing = myClients.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The client you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
