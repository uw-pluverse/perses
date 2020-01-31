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

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

/** Test for {@link IPartitionReductionPolicy.SingleNodePartitionReductionPolicy} */
@RunWith(JUnit4.class)
public class PersesTransformationPolicyTest {

  @Test
  public void test() {
    IPartitionReductionPolicy.SingleNodePartitionReductionPolicy.Builder builder =
        new IPartitionReductionPolicy.SingleNodePartitionReductionPolicy.Builder();
    builder
        .delete(true)
        .deleteChildrenOfCurrentNode(false)
        .deleteCurrentNodeAsAQualifiedNode(true)
        .replaceCurrentNodeAsAQualifiedNode(false);
    final IPartitionReductionPolicy.SingleNodePartitionReductionPolicy config = builder.build();
    Truth.assertThat(config.isDelete()).isTrue();
    Truth.assertThat(config.isDeleteChildrenOfCurrentNode()).isFalse();
    Truth.assertThat(config.isDeleteCurrentNodeAsAQualifiedNode()).isTrue();
    Truth.assertThat(config.isReplaceCurrentNodeAsAQualifiedNode()).isFalse();
  }
}
