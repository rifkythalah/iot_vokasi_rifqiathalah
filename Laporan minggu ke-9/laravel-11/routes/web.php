<?php


use Illuminate\Support\Facades\Route;
use App\Http\Controllers\GraphController;


Route::get('/graph', [GraphController::class, 'index'])->name('graph');
Route::get('/graph/export', 	[GraphController::class, 'exportToExcel'])->name('graph.export');