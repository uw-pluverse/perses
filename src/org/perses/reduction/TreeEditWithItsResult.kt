package org.perses.reduction

import org.perses.tree.spar.AbstractSparTreeEdit

data class TreeEditWithItsResult(
    val edit: AbstractSparTreeEdit,
    val testResult: TestScript.TestResult)