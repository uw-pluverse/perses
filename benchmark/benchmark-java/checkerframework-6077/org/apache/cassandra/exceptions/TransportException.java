package org.apache.cassandra.exceptions;

import org.apache.cassandra.utils.Shared;
import static org.apache.cassandra.utils.Shared.Scope.SIMULATION;

@Shared(scope = SIMULATION)
public interface TransportException {
}
