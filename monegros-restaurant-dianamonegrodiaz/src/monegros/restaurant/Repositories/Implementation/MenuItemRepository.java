package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.MenuItem;
import monegros.restaurant.entities.repository.IMenuItemRepository;

public class MenuItemRepository implements IMenuItemRepository{
	private final Set<MenuItem> myMenuItems = new HashSet<>();

    @Override
    public Optional<MenuItem> insert(MenuItem menuItem) {
        menuItem.setId(Instant.now().toEpochMilli());
        this.myMenuItems.add(menuItem);
        return Optional.of(menuItem);
    }

    @Override
    public Optional<MenuItem> update(MenuItem menuItem) {
        MenuItem existing = myMenuItems.stream()
                .filter(c -> c.equals(menuItem))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Menu Item you are trying to update does not exist"));

        existing.setFinalProduct(menuItem.getFinalProduct());
        existing.setMenu(menuItem.getMenu());
        existing.setPrice(menuItem.getPrice());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        MenuItem menuItemToDelete = new MenuItem(id);
        myMenuItems.removeIf(c -> c.equals(menuItemToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<MenuItem> findById(Long id) {
    	MenuItem existing = myMenuItems.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Menu Item you are trying to find does not exist"));

        return Optional.of(existing);
    }
}
