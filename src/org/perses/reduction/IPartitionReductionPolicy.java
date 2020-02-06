/*
 * Copyright (C) 2003-2017 Chengnian Sun.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.reduction;

import com.google.common.base.Preconditions;

/** Reduction policy for partitions. */
public interface IPartitionReductionPolicy {

  /** A configuration for perses transformations on SINGLE-node partition. */
  final class SingleNodePartitionReductionPolicy implements IPartitionReductionPolicy {

    /** Directly delete the node. */
    private final boolean delete;
    /**
     * Check whether the parent of the current node is a meta-node. If yes, check whether the
     * current node can be deleted.
     */
    private final boolean deleteCurrentNodeAsAQualifiedNode;
    /**
     * Check whether the parent of the current node is a meta-node. If yes, check whether the
     * current node can be replaced.
     */
    private final boolean replaceCurrentNodeAsAQualifiedNode;
    /** Delete the children of the current node. */
    private final boolean deleteChildrenOfCurrentNode;

    private SingleNodePartitionReductionPolicy(
        boolean delete,
        boolean deleteCurrentNodeAsAQualifiedNode,
        boolean replaceCurrentNodeAsAQualifiedNode,
        boolean deleteChildrenOfCurrentNode) {
      Preconditions.checkArgument(
          delete
              || deleteCurrentNodeAsAQualifiedNode
              || replaceCurrentNodeAsAQualifiedNode
              || deleteChildrenOfCurrentNode,
          "At least one transformation should be enabled.");
      this.delete = delete;
      this.deleteCurrentNodeAsAQualifiedNode = deleteCurrentNodeAsAQualifiedNode;
      this.replaceCurrentNodeAsAQualifiedNode = replaceCurrentNodeAsAQualifiedNode;
      this.deleteChildrenOfCurrentNode = deleteChildrenOfCurrentNode;
    }

    public boolean isDelete() {
      return delete;
    }

    public boolean isDeleteChildrenOfCurrentNode() {
      return deleteChildrenOfCurrentNode;
    }

    public boolean isDeleteCurrentNodeAsAQualifiedNode() {
      return deleteCurrentNodeAsAQualifiedNode;
    }

    public boolean isReplaceCurrentNodeAsAQualifiedNode() {
      return replaceCurrentNodeAsAQualifiedNode;
    }

    public static final class Builder {
      private boolean delete;
      private boolean deleteCurrentNodeAsAQualifiedNode;
      private boolean replaceCurrentNodeAsAQualifiedNode;
      private boolean deleteChildrenOfCurrentNode;

      public Builder delete(boolean value) {
        this.delete = value;
        return this;
      }

      public Builder deleteCurrentNodeAsAQualifiedNode(boolean value) {
        this.deleteCurrentNodeAsAQualifiedNode = value;
        return this;
      }

      public Builder replaceCurrentNodeAsAQualifiedNode(boolean value) {
        this.replaceCurrentNodeAsAQualifiedNode = value;
        return this;
      }

      public Builder deleteChildrenOfCurrentNode(boolean value) {
        this.deleteChildrenOfCurrentNode = value;
        return this;
      }

      public SingleNodePartitionReductionPolicy build() {
        return new SingleNodePartitionReductionPolicy(
            delete,
            deleteCurrentNodeAsAQualifiedNode,
            replaceCurrentNodeAsAQualifiedNode,
            deleteChildrenOfCurrentNode);
      }
    }
  }

  /** A configuration for perses transformations on MULTI-node partition. */
  final class MultiNodePartitionReductionPolicy implements IPartitionReductionPolicy {

    /** Classical HDD deletion. */
    private final boolean delete;
    /** Syntax-guided deletion. */
    private final boolean sparDeletion;

    private MultiNodePartitionReductionPolicy(boolean delete, boolean sparDeletion) {
      Preconditions.checkArgument(
          delete || sparDeletion, "At least one transformation should be enabled.");
      this.delete = delete;
      this.sparDeletion = sparDeletion;
    }

    public boolean isDelete() {
      return delete;
    }

    public boolean isSparDeletion() {
      return sparDeletion;
    }

    public static final class Builder {
      /** Delete the entire partition. */
      private boolean delete;
      /** Syntax-guided deletion. */
      private boolean sparDeletion;

      public Builder delete(boolean value) {
        this.delete = value;
        return this;
      }

      public Builder sparDeletion(boolean sparDeletion) {
        this.sparDeletion = sparDeletion;
        return this;
      }

      public MultiNodePartitionReductionPolicy build() {
        return new MultiNodePartitionReductionPolicy(delete, sparDeletion);
      }
    }
  }
}
