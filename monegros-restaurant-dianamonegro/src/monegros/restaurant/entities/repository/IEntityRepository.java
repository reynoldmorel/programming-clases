package monegros.restaurant.entities.repository;

import java.util.Collection;
import java.util.Collections;
import java.util.Optional;

public interface IEntityRepository<E, K> {
	default Optional<E> insert(E e) {
		return Optional.empty();
	}

	default Optional<E> update(E e) {
		return Optional.empty();
	}

	default Optional<E> findById(K k) {
		return Optional.empty();
	}

	default Optional<Boolean> delete(K k) {
		return Optional.empty();
	}

	default Collection<E> findAll() {
		return Collections.emptySet();
	}
}
