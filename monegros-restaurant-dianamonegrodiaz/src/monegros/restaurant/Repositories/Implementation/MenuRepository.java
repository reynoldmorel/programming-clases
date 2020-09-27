package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Menu;
import monegros.restaurant.entities.repository.IMenuRepository;

public class MenuRepository implements IMenuRepository{
	private final Set<Menu> myMenus = new HashSet<>();

    @Override
    public Optional<Menu> insert(Menu menu) {
        menu.setId(Instant.now().toEpochMilli());
        this.myMenus.add(menu);
        return Optional.of(menu);
    }

    @Override
    public Optional<Menu> update(Menu menu) {
        Menu existing = myMenus.stream()
                .filter(c -> c.equals(menu))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Menu you are trying to update does not exist"));

        existing.setFinalProducts(menu.getFinalProducts());
        existing.setName(menu.getName());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        Menu menuToDelete = new Menu(id);
        myMenus.removeIf(c -> c.equals(menuToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<Menu> findById(Long id) {

    	Menu existing = myMenus.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Menu you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
