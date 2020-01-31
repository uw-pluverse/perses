package org.perses.reduction

import org.perses.tree.spar.AbstractSparTreeEdit

data class TreeEditWithItsProgram(
    val edit: AbstractSparTreeEdit,
    val testResult: TestScript.TestResult)