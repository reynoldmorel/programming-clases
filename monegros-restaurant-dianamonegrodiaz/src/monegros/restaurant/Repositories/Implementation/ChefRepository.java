package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Chef;
import monegros.restaurant.entities.repository.IChefRepository;

public class ChefRepository implements IChefRepository{
    private final Set<Chef> myChefs = new HashSet<>();

    @Override
    public Optional<Chef> insert(Chef chef) {
        chef.setId(Instant.now().toEpochMilli());
        this.myChefs.add(chef);
        return Optional.of(chef);
    }

    @Override
    public Optional<Chef> update(Chef chef) {
        Chef existing = myChefs.stream()
                .filter(c -> c.equals(chef))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Chef you are trying to update does not exist"));

        existing.setAddress(chef.getAddress());
        existing.setAge(chef.getAge());
        existing.setName(chef.getName());
        existing.setLastName(chef.getLastName());
        existing.setPhone(chef.getPhone());
        existing.setExperience(chef.getExperience());
        existing.setCode(chef.getCode());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        Chef chefToDelete = new Chef(id);
        myChefs.removeIf(c -> c.equals(chefToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<Chef> findById(Long id) {
    	Chef existing = myChefs.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The chef you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
